# $NetBSD: Makefile,v 1.4 2012/10/07 20:11:07 asau Exp $

DISTNAME=	wgetpro-0.1.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wgetpro/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://wgetpro.sourceforge.net/
COMMENT=	Wget with "PRO" features

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
