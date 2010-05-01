# $NetBSD: Makefile,v 1.1.1.1 2010/05/01 23:11:52 thomasklausner Exp $
#

DISTNAME=	notmuch-0.3.1
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notmuchmail.org/
COMMENT=	Mail indexer
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../mail/gmime24/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../wip/talloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
