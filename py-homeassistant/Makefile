# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-homeassistant-0.03
CATEGORIES=	meta-pkgs

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.home-assistant.io/
COMMENT=	Meta-package for prereqs for Home Assistant
LICENSE=	modified-bsd

META_PACKAGE=	yes

# This package is currently tuned for and tested on NetBSD 9 amd64 and
# is probably ok on NetBSD 10.

# Home Assistant (HA) upstream pins exact dependencies as a general
# practice, and this is incompatible with packaging systems.  Thus,
# this package does not actually install the python package
# homeasssistant.  Instead, it has dependencies so that after
# installing it, trying to build homeassistant in a venv it can
# succeed.  HA has many optional modules, so there is no one set of
# dependencies; we steer towards the union of reasonable
# installations, erring on the side of depending on more rather than
# less.

# Despite depending on programs as build tools, record a full
# dependency so that "pkgin ar" after installing this package will not
# remove e.g. the rust compiler.

# The vast majority of HA components are just python (perhaps a chain
# of dependencies) and build straightforwardly with "bin/pip install";
# these are therefore not addressed here.


## PYTHON

# Building HA in a venv requires virtualenv and thus python.  That
# includes sqlite3 because the rest of the world thinks that is part
# of python.

.include "../../lang/python/pyversion.mk"
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

## BUILD TOOLS

# Builds in the venv will use pkg-config, and invoke rust and gfortran.
# NB: One must add gfortran's bindir to the PATH for the venv build.
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf

RUST_RUNTIME=	yes		# record a dependency
.include "../../lang/rust/rust.mk"

# FORTRAN: choose the version that matches the base  compiler.
.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-9].*)
FORTRAN_VERSION=10
.else
FORTRAN_VERSION=7
.endif
BUILDLINK_DEPMETHOD.gcc${FORTRAN_VERSION}=	full
.include "../../lang/gcc${FORTRAN_VERSION}/buildlink3.mk"


## LIBRARIES
# These are in the order that HA tries to install them when started in
# a venv that more or less only has homeassistant's dependencies
# installed.

# \todo Sort these properly.
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

# HA installs Pillow, and it depends on a lot of image libraries.
# Rather than open-coding that set, just depend on Pillow even if the
# install is wasted.  Hope that our version and HA's version are close
# enough.
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

# The standard approach for recorder is to use pgsql.  (The testing
# approach is sqlite3, and that's depended on above.  It seems sqlite3
# is needed even if recorded is not configured to use it, but we
# choose not to fight that.)  HA uses this via SQLAlchemy.
.include "../../mk/pgsql.buildlink3.mk"

# \todo In lieu of https://pypi.org/project/ha-av/ or
# https://pypi.org/project/av/ we just depend on ffmpeg4.
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4

DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl

.include "../../mk/bsd.prefs.mk"


## NEEDED WORKAROUNDS
# \todo Hoist these somehow to a script or fix upstream.
# This section describes workarounds to enable the venv to build.

## ha-av
#
# ffmpeg4 installs to /usr/pkg/lib/ffmpeg4, but pkg_alternatives does
# not provide library links.  A strategy that works is to symlink from
# /usr/pkg/lib, and a strategy that might work is to set
# PKG_CONFIG_PATH.
#
#   export PKG_CONFIG_PATH=/usr/pkg/lib/ffmpeg4/pkgconfig
#
# ffmpeg's pkgconfig files have "-Wl,-rpath,/usr/pkg/lib/ffmpeg4/lib",
# but PyAV's setup.py is buggy and looks at flags to see if they are
# known and doesn't support -Wl,-rpath.  Changing to -R makes it work.
# This is a bug in PyAV.  \todo File a fix.

## cryptography
# As of 41, the build fails to find openssl on NetBSD 9, likely a bug.
# https://docs.rs/openssl/latest/openssl/#automatic advises
#   export OPENSSL_DIR=/usr

.include "../../mk/bsd.pkg.mk"
