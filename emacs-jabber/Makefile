# $NetBSD: Makefile,v 1.13 2012/09/28 22:07:32 asau Exp $
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

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

GCONF_SCHEMAS+=	gconf/emacs-jabber.schemas

.include "../../editors/emacs/modules.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
