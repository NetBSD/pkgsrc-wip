# $NetBSD: Makefile,v 1.12 2009/12/27 14:13:37 jihbed Exp $
#

DISTNAME=	emacs-jabber-0.8.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	http://garr.dl.sourceforge.net/project/emacs-jabber/emacs-jabber/0.8.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://emacs-jabber.sourceforge.net/
COMMENT=	Minimal jabber client for emacs
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

GCONF_SCHEMAS+=	gconf/emacs-jabber.schemas

.include "../../editors/emacs/modules.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
