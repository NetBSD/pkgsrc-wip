# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 06:18:29 jdwhite Exp $
#

DISTNAME=		owl-2.1.11
CATEGORIES=		chat
MASTER_SITES=		http://www.ktools.org/dist/owl/

MAINTAINER=		jdwhite@jdwhite.org
HOMEPAGE=		http://www.ktools.org/dist/owl/
COMMENT=		Curses-based instant messaging client

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

DEPENDS+=		ncurses>=5.0:../../devel/ncurses

INSTALLATION_DIRS+=	share/doc/owl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/intro.txt ${PREFIX}/share/doc/owl/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../chat/zephyr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
