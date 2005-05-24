# $NetBSD: Makefile,v 1.4 2005/05/24 10:44:36 rillig Exp $
#

DISTNAME=		tinycobol-0.61
CATEGORIES=		devel
MASTER_SITES=           ${MASTER_SITE_SOURCEFORGE:=tiny-cobol/}
#MASTER_SITES=		http://umn.dl.sourceforge.net/sourceforge/tiny-cobol/

MAINTAINER=	        lrfurtado@yahoo.com.br
HOMEPAGE=		http://umn.dl.sourceforge.net/sourceforge/tiny-cobol/
COMMENT=                Tiny COBOL compiler for IA32 platforms

CONFIGURE_ARGS+=	--with-libdb=2

ONLY_FOR_PLATFORM= *-*-i386

USE_TOOLS+=		gmake bison

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../databases/db/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
