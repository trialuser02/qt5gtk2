#!/bin/sh

VERSION=0.3

NAME=qt5gtk2

TARBALL=$NAME-$VERSION

mkdir -p extras/package/sources
git archive --format=tar --prefix=$TARBALL/ $VERSION | bzip2 > extras/package/sources/$TARBALL.tar.bz2
