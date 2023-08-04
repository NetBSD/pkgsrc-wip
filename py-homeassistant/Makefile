# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-homeassistant-0.02
CATEGORIES=	meta-pkgs

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.home-assistant.io/
COMMENT=	Meta-package for prereqs for Home Assistant
LICENSE=	modified-bsd

META_PACKAGE=	yes

# This package intends to set up for the union of reasonable Home
# Assistant (HA) installations within a venv, erring on the side of
# depending on more rather than less.  The vast majority of HA
# components (integrations, or the core) are just python, often
# depending on another python module.  These build straightforwardly
# with "bin/pip install".  However, some modules depend on C
# libraries, some depend on Fortran, and some use rust to build.  This
# package is primarily intended to ease those issues.

# This package is currently tuned for NetBSD 9.

# The set of packages wrapping libraries is currently:
#   - cryptography (http for SSL)
#   - postgresql (standard approach for database)
#   - sqlite3 (testing approach for database)
#   - av and numpy (stream component, which is part of default config)
#   - PIL (needed by 8 components)
# and build tools
#   - pkg-config
#   - rust (for cryptography in the venv)
#   - gfortran (for numpy in the venv)

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
# \todo In lieu of https://pypi.org/project/ha-av/ or
# https://pypi.org/project/av/ we just depend on ffmpeg4.
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl

.include "../../mk/bsd.prefs.mk"


# Depend on fortran, because HA will use it at pip-install time.
#.include "../../mk/compiler/gfortran.mk"

# Hack around gfortran issues.
.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-9].*)
# \todo Consider forcing 10 always for now.
FORTRAN_VERSION=10
.else
FORTRAN_VERSION=7
.endif
BUILDLINK_DEPMETHOD.gcc${FORTRAN_VERSION}=	full
.include "../../lang/gcc${FORTRAN_VERSION}/buildlink3.mk"

RUST_RUNTIME=	yes
.include "../../lang/rust/rust.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/pgsql.buildlink3.mk"

### NEEDED WORKAROUNDS
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
# As of 40, the build fails to find openssl on NetBSD 9, likely a bug.
# https://docs.rs/openssl/latest/openssl/#automatic advises
#   export OPENSSL_DIR=/usr

.include "../../mk/bsd.pkg.mk"
