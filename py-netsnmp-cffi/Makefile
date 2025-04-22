# $NetBSD$

DISTNAME=	netsnmp-cffi-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	netsnmp-cffi

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/netsnmp-cffi
COMMENT=	CFFI-based python interface to net-snmp
LICENSE=	apache-2.0

USE_LANGUAGES+=	c
# Needs python >= 39
PYTHON_VERSIONS_INCOMPATIBLE+=	27

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-*}
TIME_T_CMD=	${CC} -E -dD - </dev/null | \
		sed -n -e '/__INT64_TYPE__/s/\#define __INT64_TYPE__ //p'
TIME_T=		${TIME_T_CMD:sh}
SUSECONDS_T=	int
.else
# what was there before, applies at least on Linux:
TIME_T=		long
SUSECONDS_T=	long
.endif
FIX_TIME_T=	src/netsnmpy/netsnmp_ffi.py

pre-configure:
	cd ${WRKSRC}; \
	for f in ${FIX_TIME_T}; do \
		sed -e "s/@TIME_T@/${TIME_T}/g" <$$f >$$f.new; \
		mv $$f.new $$f; \
		sed -e "s/@SUSECONDS_T@/${SUSECONDS_T}/g" <$$f >$$f.new; \
		mv $$f.new $$f; \
	done

.include "../../net/net-snmp/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
