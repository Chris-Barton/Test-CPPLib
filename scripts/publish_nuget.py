import zipfile
import sys
import os
import tempfile
import fnmatch

repo = sys.argv[2]


def updateZip(zipname, file_glob, old, new):
    # generate a temp file
    filecontents = ""
    filename = ""
    tmpfd, tmpname = tempfile.mkstemp(dir=os.path.dirname(zipname))
    os.close(tmpfd)

    # create a temp copy of the archive without filename
    with zipfile.ZipFile(zipname, 'r') as zin:
        with zipfile.ZipFile(tmpname, 'w') as zout:
            zout.comment = zin.comment  # preserve the comment
            for item in zin.infolist():
                if not fnmatch.fnmatch(item.filename, file_glob):
                    zout.writestr(item, zin.read(item.filename))

                else:
                    filecontents = zin.read(item.filename).decode()
                    filecontents = filecontents.replace(old, new)
                    filename = item.filename
                    print(filecontents)
    # replace with the temp archive
    os.remove(zipname)
    os.rename(tmpname, zipname)

    # now add filename with its new data
    with zipfile.ZipFile(zipname, mode='a', compression=zipfile.ZIP_DEFLATED) as zf:
        zf.writestr(filename, filecontents)


updateZip(sys.argv[1], '*.nuspec', '  </metadata>', f'    <repository type="git" url="{repo}"/>    \n  </metadata>')
is_windows = sys.platform.startswith('win')
