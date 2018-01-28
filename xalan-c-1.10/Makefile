# $NetBSD: Makefile,v 1.2 2013/02/18 00:31:27 asau Exp $
#

DISTNAME=	Xalan-C_1_10_0-src
PKGNAME=	xalan-c-1.10
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://archive.apache.org/dist/xml/xalan-c/source/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

DISTFILES+=	xerces-c-src_2_8_0.tar.gz
SITES.xerces-c-src_2_8_0.tar.gz=	${MASTER_SITE_APACHE:=xerces/c/2/sources/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xalan-c/l
COMMENT=	XSLT processor of the Apache Project

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/xml-xalan/c
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
.if ${LOWER_OPSYS} == "SunOS"
XALAN_PLATFORM=	solaris
.elif ${LOWER_OPSYS} == "Darwin"
XALAN_PLATFORM=	macosx
.else
XALAN_PLATFORM=	${LOWER_OPSYS}
.endif
XALAN_ENV=	XERCESCROOT="${WRKDIR}/xerces-c-src_2_8_0" XALANCROOT="${WRKDIR}/xml-xalan/c" LD_LIBRARY_PATH="${PREFIX}/lib:${LD_LIBRARY_PATH} -DXALAN_STRICT_ANSI_HEADERS"

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./runConfigure
CONFIGURE_ARGS+=	-C --prefix=${PREFIX}
CONFIGURE_ARGS+=	-p ${XALAN_PLATFORM}
CONFIGURE_ARGS+=	-r pthread
# 1.7.0 needs the following argument.
#CONFIGURE_ARGS+=	-m inmem

CONFIGURE_ENV+=	${XALAN_ENV}
MAKE_ENV+=	${XALAN_ENV}

pre-configure:
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../wip/xerces-c-2.8.0/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
