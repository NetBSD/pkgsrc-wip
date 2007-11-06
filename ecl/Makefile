# $NetBSD: Makefile,v 1.7 2007/11/06 19:17:18 asau Exp $
#

DISTNAME=		ecl-0.9i
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

.include "../../mk/bsd.pkg.mk"
