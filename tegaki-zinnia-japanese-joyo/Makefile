# $NetBSD: Makefile,v 1.1.1.1 2010/01/14 10:38:56 obache Exp $
#

DISTNAME=	tegaki-zinnia-japanese-joyo-0.3
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://www.tegaki.org/releases/0.3/models/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project handwriting model for Zinnia-Japanese (joyo)
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	tegaki-zinnia-japanese-[0-9]*
CONFLICTS+=	tegaki-zinnia-japanese-light-[0-9]*
CONFLICTS+=	tegaki-zinnia-japanese-kyoiku-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	share/tegaki/models/zinnia

INSTALL_MAKE_FLAGS+=	installpath=${DESTDIR}${PREFIX}/share/tegaki/models/zinnia

.include "../../mk/bsd.pkg.mk"
