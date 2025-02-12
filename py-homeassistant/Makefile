# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-homeassistant-0.07
PKGREVISION=	1
CATEGORIES=	meta-pkgs

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.home-assistant.io/
COMMENT=	Meta-package for prereqs for Home Assistant
LICENSE=	modified-bsd

# This package is intended to be usable with the most recent stable
# branch; modifications should either be tested in that environment or
# sent to ${MAINTAINER}.

META_PACKAGE=	yes

# This package is currently tuned for and tested on NetBSD/amd64 9 and
# 10.

# Home Assistant (HA) upstream pins exact dependencies as a general
# practice, and this is incompatible with packaging systems.  Thus,
# this package does not actually install the python package
# homeasssistant.  Instead, it has dependencies so that after
# installing it, trying to build homeassistant in a venv it can
# succeed.  HA has many optional modules, so there is no one set of
# dependencies; we steer to the union of reasonable installations,
# erring on the side of depending on more rather than less.

# Despite depending on programs that are build tools, record a full
# dependency so that "pkgin ar" after installing this package will not
# remove e.g. the rust compiler.  The point is that while that's a
# build-time dependency in pkgsrc, it's a run-time dependency for this
# package, because the user will do builds when this package is
# installed.

# The vast majority of HA components are just python (perhaps a chain
# of dependencies) and build straightforwardly with "bin/pip install";
# these are therefore not addressed here.

## PYTHON

# HA 2024.4 requires 3.12
# HA 2025.2 requires 3.13
PYTHON_VERSIONS_ACCEPTED=313
.include "../../lang/python/pyversion.mk"

# Building HA in a venv requires virtualenv
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

## BUILD TOOLS

# Builds in the venv will use cmake, pkg-config, and invoke gcc,
# fortran and rust.
# NB: One must add gcc/gfortran's bindir to the PATH for the venv build.
DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf

# GCC
# \todo Depend on gcc10, because numpy needs it, and venv build
# scripts will thus require it.  For now, requiring gfortran 10 adds
# the dependency.

# FORTRAN
USE_LANGUAGES+=	fortran77
GFORTRAN_VERSION=	10
# \todo Revisit the version, so e.g. the version matching native gcc
# will be used on NetBSD-current.
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

# generic and stream require PyAV which depends on ffmpeg >= 7.
DEPENDS+=	ffmpeg7-[0-9]*:../../multimedia/ffmpeg7

# onvif integration requires onvif_zeep_async which depends on lxml
# depends on libxml2 and libxslt.
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

.include "../../mk/bsd.prefs.mk"

## NEEDED WORKAROUNDS
# This section describes workarounds to enable the venv to build.
# \todo Hoist these somehow to a script or fix upstream.

## ha-av
#
# ffmpeg7 installs to /usr/pkg/lib/ffmpeg7, and HA expects to just find ffmpeg
#   export PKG_CONFIG_PATH=/usr/pkg/lib/ffmpeg7/pkgconfig
#
# ffmpeg's pkgconfig files have "-Wl,-rpath,/usr/pkg/lib/ffmpeg7/lib",
# but PyAV's setup.py is buggy and looks at flags to see if they are
# known and doesn't support -Wl,-rpath.  Changing to -R makes it work.
# This is a bug in PyAV.  \todo File a fix.
#
# PyAV further seems to not pass -R correctly, and the workaround is
# to symlink the ffmpeg shlibs into /usr/pkg/lib.

## cryptography
#
# As of 41, the build fails to find openssl.
# https://docs.rs/openssl/latest/openssl/#automatic advises
#   export OPENSSL_DIR=/usr

.include "../../mk/bsd.pkg.mk"
