# $NetBSD: Makefile,v 1.1.1.1 2010/03/19 07:26:15 othyro Exp $
#

DISTNAME=	emovix-0.9.0
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.sourceforge.net/project/movix/eMoviX/0.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://movix.sourceforge.net/
COMMENT=	Tiny GNU/Linux distribution that plays video files when booted
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl

SUBST_CLASSES+=		cp
SUBST_STAGE.cp=		pre-install
SUBST_FILES.cp=		Makefile
SUBST_SED.cp=		-e "s|cp -a {translations,mplayer-fonts,keyboard-i18n,backgrounds}|${CP} -RPp translations mplayer-fonts keyboard-i18n backgrounds|g"
SUBST_MESSAGE.cp=	Fixing hardcoded cp path

.include "../../mk/bsd.pkg.mk"
