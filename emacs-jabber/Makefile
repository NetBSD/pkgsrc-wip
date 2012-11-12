# $NetBSD: Makefile,v 1.14 2012/11/12 15:59:48 othyro Exp $
#

DISTNAME=	emacs-jabber-0.8.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=emacs-jabber/}
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
