# $NetBSD: Makefile,v 1.3 2008/05/24 15:34:14 tnn2 Exp $
#

DISTNAME=	radare-0.8.6
CATEGORIES=	wip sysutils
MASTER_SITES=	http://radare.nopcode.org/get/

MAINTAINER=	pancake@youterm.com
HOMEPAGE=	http://radare.nopcode.org/
COMMENT=	advanced commandline hexadecimal editor

USE_LANGUAGES=	c perl

USE_TOOLS=	gmake
USE_GNU_READLINE=	YES
GNU_CONFIGURE=	yes

.include "options.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
