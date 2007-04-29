# $NetBSD: Makefile,v 1.1.1.1 2007/04/29 12:02:56 poppnk Exp $
#

DISTNAME=	radare-0.8
CATEGORIES=	wip sysutils
MASTER_SITES=	http://radare.nopcode.org/get/

MAINTAINER=	pancake@youterm.com
HOMEPAGE=	http://radare.nopcode.org/
COMMENT=	advanced commandline hexadecimal editor

USE_LANGUAGES=	c perl

USE_TOOLS=	gmake
USE_GNU_READLINE=       YES
GNU_CONFIGURE=	yes

.include "options.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
