# $NetBSD: Makefile,v 1.9 2012/10/07 16:23:17 asau Exp $

DISTNAME=	sudoscript-2.1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sudoscript/} \
		http://egbok.com/sudoscript/

MAINTAINER=	hbo@egbok.com
HOMEPAGE=	http://www.egbok.com/sudoscript/
COMMENT=	Audited shells with sudo(8) and script(1)

PKG_DESTDIR_SUPPORT=	none

MESSAGE_SUBST+=	DISTNAME=${DISTNAME}

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

NO_BUILD=		Yes
USE_TOOLS+=		gmake
USE_TOOLS+=		perl

.include "../../mk/bsd.pkg.mk"
