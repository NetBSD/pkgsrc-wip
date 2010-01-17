# $NetBSD: Makefile,v 1.3 2010/01/17 12:03:33 thomasklausner Exp $

DISTNAME=	wgetpro-0.1.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wgetpro/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	clamiax@gmail.com
HOMEPAGE=	http://wgetpro.sourceforge.net/
COMMENT=	Wget with "PRO" features

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
