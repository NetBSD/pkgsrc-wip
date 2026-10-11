# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-homeassistant-0.13
CATEGORIES=	meta-pkgs

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.home-assistant.io/
COMMENT=	Meta-package for prereqs for Home Assistant
LICENSE=	modified-bsd

# This package is intended to be usable with the most recent stable
# branch; modifications should either be tested in that environment or
# sent to ${MAINTAINER}.

META_PACKAGE=	yes

# This package is currently tuned for and tested on NetBSD/amd64 10.
# As of 2026-03, NetBSD 9 is abandoned, and NetBSD 11 support has not
# yet been started.

# Home Assistant (HA) upstream pins exact dependencies as a general
# practice, and this is incompatible with packaging systems.  Thus,
# this package does not actually install the python package
# homeasssistant.  Instead, it has dependencies so that after
# installing it, trying to build homeassistant in a venv it can
# succeed.  HA has many optional modules, so there is no one set of
# dependencies; we steer to the union of reasonable installations,
# erring on the side of depending on more rather than less.

# Even for packages that are normally thought of as build tools,
# record a full dependency.  The point is that a user will, after this
# package is installed, use those tools to build HA.

## PYTHON

# HA 2024.4 requires 3.12
# HA 2025.2 requires 3.13
# HA 2026.2 requires 3.14
PYTHON_VERSIONS_ACCEPTED=314
.include "../../lang/python/pyversion.mk"

# Building HA in a venv requires virtualenv
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

## BUILD TOOLS

# Builds in the venv will use cmake, pkg-config, and invoke gcc,
# fortran and rust.
# NB: One must add gcc/gfortran's bindir to the PATH for the venv build.
DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf

# Generally, choose a gcc/fortran to match the base compiler, except
# that any system with base gcc < 10 is not supported anyway.  While
# we don't specifically depend on gcc proper in this package, venv
# builds will expect the C/C++ part of the compiler also.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
.  if !empty(OS_VERSION:M10\.*)
GFORTRAN_VERSION?=	10
.  elif !empty(OS_VERSION:M11.[0-8]*)
GFORTRAN_VERSION?=	12
.  elif !empty(OS_VERSION:M11.99.*)
GFORTRAN_VERSION?=	14
.  endif
.endif
# On a system without a known base compiler, pick
GFORTRAN_VERSION?=	10

# FORTRAN
USE_LANGUAGES+=	fortran77
.include "../../mk/compiler/gfortran.mk"

RUST_RUNTIME=	yes		# record a dependency
.include "../../lang/rust/rust.mk"

## LIBRARIES needed to build modules that HA needs

# The standard approach for recorder is to use pgsql.  We choose 18
# and do not try to follow a chosen pgsql. (HA uses this, like all
# databases, via SQLAlchemy, and then pyscopg2).
.include "../../mk/pgsql.buildlink3.mk"
DEPENDS+=	postgresql18-server-[0-9]*:../../databases/postgresql18-server

# Various modules (e.g. mobile_app) need numpy.  numpy needs blas
# (even though HA probably does not use numpy blas-ish methods), and
# the build will prefer openblas to cblas.  Thus, if the build system
# for the venv has openblas, the wheels will later need openblas.
# Depend on openblas to force this, as a second-class method of
# controlling dependencies.
DEPENDS+=	openblas-[0-9]*:../../math/openblas

# HA culture uses yaml enough that I say it should be installed on the
# host for use, even if there will be a copy in the venv.
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

# HA will build various python modules via pip; depend on them to
# force dependencies to be installed.
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-grpcio-[0-9]*:../../net/py-grpcio

# generic camera and stream require PyAV which depends on ffmpeg >= 8.
DEPENDS+=	ffmpeg8-[0-9]*:../../multimedia/ffmpeg8

# onvif integration requires onvif_zeep_async which depends on lxml
# which depends on libxml2 and libxslt.
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

## NEEDED WORKAROUNDS
# This section describes workarounds to enable the venv to build.
# They aren't really part of this package, but are included as helpful
# to anyone wanting to use this package.
# \todo Hoist these somehow to a script or fix upstream.

## ha-av
#
# ffmpeg8 installs to /usr/pkg/lib/ffmpeg8, and HA expects to just find ffmpeg
#   export PKG_CONFIG_PATH=/usr/pkg/lib/ffmpeg8/pkgconfig
#
# ffmpeg's pkgconfig files have "-Wl,-rpath,/usr/pkg/lib/ffmpeg8/lib",
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
