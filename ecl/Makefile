# $NetBSD: Makefile,v 1.8 2007/12/29 18:24:04 asau Exp $
#

DISTNAME=		ecl-0.9j
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ecls.sourceforge.net/index.html
COMMENT=		Embeddable Common Lisp

WRKSRC=			${WRKDIR}/${DISTNAME}-build/

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_SCRIPT=	../${DISTNAME}/src/configure
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

post-extract:
	${MKDIR} ${WRKSRC}
post-install:
	${INSTALL_DATA_DIR} share/doc/${PKGNAME}/html
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/*

.include "../../mk/bsd.pkg.mk"
