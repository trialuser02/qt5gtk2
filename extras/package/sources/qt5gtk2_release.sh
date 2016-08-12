#!/bin/sh

if [ ! -d "cache" ]; then
mkdir cache
fi


cd cache

echo "Receiving sources.."
if [ ! -d "qt5gtk2-git" ]; then
git clone --depth 1 --branch master https://trialuser02@bitbucket.org/trialuser02/qt5gtk2.git qt5gkt2-git
fi

cd qt5gkt2-git
git pull
git checkout master
echo "Creating changelog.."
git log > ChangeLog.git

TARBALL=qt5gtk2-0.1


echo Sources name: $TARBALL
cd ..
if [ -d $TARBALL ]; then
echo "Removing previous directory.."
rm -rf $TARBALL
fi

echo "Copying sources.."
cp -r qt5gkt2-git $TARBALL

cd $TARBALL

echo "Removing directories"
rm -rf .git
rm -rf extras
rm -rf tests
cd ..

echo "Creating tarball.."
tar vcjf ${TARBALL}.tar.bz2 ${TARBALL}/

echo "Removing temporary directory.."
rm -rf ${TARBALL}

#echo "Creating md5 sum.."
#md5sum -b ${TARBALL}.tar.bz2 > ${TARBALL}.tar.bz2.md5sum

echo "Moving released files.."
cd ..
if [ ! -d "files" ]; then
mkdir files
fi
mv cache/${TARBALL}.tar.bz2 files/
#mv cache/${TARBALL}.tar.bz2.md5sum files/

echo ""
echo "****** RELEASED FILES *******"
echo "Tarball: ${TARBALL}.tar.bz2"
#echo "MD5: ${TARBALL}.tar.bz2.md5sum"
echo "*****************************"
echo ""
echo "Finished"
