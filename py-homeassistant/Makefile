# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-homeassistant-0.07
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

# HA 2024.4 requires 3.12
PYTHON_VERSIONS_ACCEPTED=312
.include "../../lang/python/pyversion.mk"

# Building HA in a venv requires virtualenv
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

## BUILD TOOLS

# Builds in the venv will use cmake, pkg-config, and invoke rust and
# gfortran.									      
# NB: One must add gfortran's bindir to the PATH for the venv build.
DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf

# GCC
# \todo Depend on gcc10, because numpy needs it, and venv build
# scripts will thus require it.

# FORTRAN
USE_LANGUAGES+=	fortran77
.include "../../mk/compiler/gfortran.mk"

RUST_RUNTIME=	yes		# record a dependency
.include "../../lang/rust/rust.mk"

## LIBRARIES needed to build modules that HA needs

# The standard approach for recorder is to use pgsql.  HA uses this,
# like all databases, via SQLAlchemy, but it does not install
# psycopg2, which of course expects pgsql libs.
.include "../../mk/pgsql.buildlink3.mk"

# Various modules (e.g. mobile_app) need numpy.  numpy needs blas
# (even though HA probably does not use numpy blas-ish methods), and
# the build will prefer openblas to cblas.  Thus, if the build system
# for the venv has openblas, the wheels will later need openblas.
# Depend on openblas to force this, as a second-class method of
# controlling dependencies.
DEPENDS+=	openblas-[0-9]*:../../math/openblas

# HA installs yaml \todo despite it not showing in bin/pip freeze
# \todo Figure out if this is really needed.
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

# HA will build cryptography, Pillow and nacl, so depend on them to
# force deps.
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl

# stream integration needs ha-ffmpeg depends on ffmpeg
# \todo Reconsider ffmpeg6 vs 4.
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4

# onvif integration needs onvif_zeep_async depends on lxml depends on libxml2 libxslt
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "../../mk/bsd.prefs.mk"

## NEEDED WORKAROUNDS
# This section describes workarounds to enable the venv to build.
# \todo Hoist these somehow to a script or fix upstream.

## ha-av
#
# ffmpeg4 installs to /usr/pkg/lib/ffmpeg4, and HA expects to just find ffmpeg
#   export PKG_CONFIG_PATH=/usr/pkg/lib/ffmpeg4/pkgconfig
#
# ffmpeg's pkgconfig files have "-Wl,-rpath,/usr/pkg/lib/ffmpeg4/lib",
# but PyAV's setup.py is buggy and looks at flags to see if they are
# known and doesn't support -Wl,-rpath.  Changing to -R makes it work.
# This is a bug in PyAV.  \todo File a fix.

## cryptography
#
# As of 41, the build fails to find openssl on NetBSD 9.
# https://docs.rs/openssl/latest/openssl/#automatic advises
#   export OPENSSL_DIR=/usr

.include "../../mk/bsd.pkg.mk"
