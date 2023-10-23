# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-homeassistant-0.04
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

# HA 2023.8 only works with Python 3.11
PYTHON_VERSIONS_ACCEPTED=311
.include "../../lang/python/pyversion.mk"

# Building HA in a venv requires virtualenv
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

## BUILD TOOLS

# Builds in the venv will use pkg-config, and invoke rust and gfortran.
# NB: One must add gfortran's bindir to the PATH for the venv build.
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf

RUST_RUNTIME=	yes		# record a dependency
.include "../../lang/rust/rust.mk"

# FORTRAN: choose the version that matches the base  compiler.
USE_LANGUAGES+=	fortran77
.include "../../mk/compiler/gfortran.mk"

## LIBRARIES needed to build modules that must be installed before HA runs

# mjpeg needs numpy but does not install it
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

# The standard approach for recorder is to use pgsql.  HA uses this,
# like all databases, via SQLAlchemy, but it does not install
# psycopg2, which of course expects pgsql libs.
.include "../../mk/pgsql.buildlink3.mk"

## LIBRARIES needed when HA first runs
# These are in the order that HA tries to install them when started in
# a venv that more or less only has homeassistant's dependencies
# installed.

# \todo Sort these properly.
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

# HA installs Pillow, and it depends on a lot of image libraries.
# Rather than open-coding that set, just depend on Pillow even if the
# install is wasted.  Hope that our version and HA's version are close
# enough.
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow


# HA builds ha-ffmpeg, likely as a dependency of ha-av.  Ensure ffmpeg
# libs are present, as this seems sufficient.
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4

# \todo Explain what's really needed. In addition to crypto libs, this
# depends on cffi.
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
