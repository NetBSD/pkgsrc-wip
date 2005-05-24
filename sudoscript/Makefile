# $NetBSD: Makefile,v 1.5 2005/05/24 10:31:43 rillig Exp $

DISTNAME=	sudoscript-2.1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sudoscript/} \
		http://egbok.com/sudoscript/

MAINTAINER=	hbo@egbok.com
HOMEPAGE=	http://www.egbok.com/sudoscript/
COMMENT=	Audited shells with sudo(8) and script(1)

MESSAGE_SUBST+=	DISTNAME=${DISTNAME}
MESSAGE_SUBST+=	PREFIX=${PREFIX}

PERMIT_PACKAGE_CDROM=	Yes
PERMIT_PACKAGE_FTP=	Yes
PERMIT_DISTFILES_CDROM=	Yes
PERMIT_DISTFILES_FTP=	Yes

NO_BUILD=		Yes
NO_REGRESS=		Yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
