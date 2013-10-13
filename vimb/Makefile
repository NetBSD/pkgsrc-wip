# $NetBSD: Makefile,v 1.2 2013/10/13 21:01:15 leot1990 Exp $

DISTNAME=	0.1.10
PKGNAME=	vimb-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://github.com/fanglingsu/vimb/archive/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

FETCH_USING=	curl	# XXX: https://

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

#
# git is required to define GIT_VERSION.
#
SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-build
SUBST_MESSAGE.configmk=	Remove GIT_VERSION in config.mk
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e '/^GIT_VERSION.*=/d'

MAKE_ENV+=	MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../net/libsoup24/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
