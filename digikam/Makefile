# $NetBSD: Makefile,v 1.6 2009/01/09 09:07:37 thomasklausner Exp $
#

DISTNAME=	digikam-0.10.0-beta5
PKGNAME=	digikam-0.10.0beta5
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://digikam.sourceforge.net/
COMMENT=	Advanced digital photo management application (KDE4)

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

REPLACE_PERL=	utilities/scripts/digitaglinktree
USE_CMAKE=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gawk msgfmt perl:run pkg-config

.include "../../mk/bsd.prefs.mk"

# As of at least NetBSD-4.0 the shipped gettext cannot handle the .po files,
# so we strip out usage of the newer features (context and fuzzy matches)
.if (${OPSYS} == "NetBSD")
post-patch:
	for f in ${WRKSRC}/po/*/digikam.po ; do \
	    mv $$f $$f.original ; \
	    ${AWK} -f ${FILESDIR}/msgfmtstrip $$f.original > $$f ; \
	done
.endif

.include "options.mk"

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdemultimedia4/buildlink3.mk"
# for libkdcraw>=0.4.0
BUILDLINK_API_DEPENDS.kdegraphics4+=	kdegraphics4>=4.1.2nb1
.include "../../wip/kdegraphics4/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
