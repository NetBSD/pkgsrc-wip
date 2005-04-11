# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:22 tvierling Exp $

DISTNAME=	gaim-otr-2.0.2
CATEGORIES=	chat
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.cypherpunks.ca/otr
COMMENT=	GAIM plugin for private, deniable messaging

# 2.0.2 is not released.  See patch gdt sent to otr-dev to get 2.0.2
# sources from 2.0.1, autoreconf, ./configure and make dist.

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../wip/libotr/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/gaim/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
