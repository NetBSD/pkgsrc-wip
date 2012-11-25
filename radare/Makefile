# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:30 othyro Exp $
#

DISTNAME=	radare-0.8.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://radare.nopcode.org/get/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://radare.nopcode.org/
COMMENT=	Advanced commandline hexadecimal editor

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES=	c perl

USE_TOOLS=	gmake
USE_GNU_READLINE=	YES
GNU_CONFIGURE=	yes

.include "options.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
