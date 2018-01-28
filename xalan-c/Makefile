# $NetBSD: Makefile,v 1.2 2013/02/18 00:31:27 asau Exp $
#

DISTNAME=	xalan_c-1.11-src
PKGNAME=	${DISTNAME:S|_c|-c|:S|-src||}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=xalan/xalan-c/sources/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

DISTFILES+=	xerces-c-3.1.1.tar.gz
SITES.xerces-c-3.1.1.tar.gz=	${MASTER_SITE_APACHE:=xerces/c/3/sources/}
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xalan-c/
COMMENT=	XSLT processor of the Apache Project

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/xalan-c-1.11/c
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
XALAN_ENV=	XERCESCROOT="${WRKDIR}/xerces-c-3.1.1" XALANCROOT="${WRKDIR}/xalan-c-1.11/c" LD_LIBRARY_PATH="${PREFIX}/lib:${LD_LIBRARY_PATH}"

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
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
