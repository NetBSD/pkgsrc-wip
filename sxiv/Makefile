# $NetBSD: Makefile,v 1.10 2015/03/10 18:06:43 leot1990 Exp $
#

DISTNAME=	sxiv-1.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=muennich/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://github.com/muennich/sxiv
COMMENT=	Simple (or small or suckless) X Image Viewer
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile.
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's,^CPPFLAGS.*,& -DVERSION=\\"${PKGVERSION_NOREV}\\",'
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
