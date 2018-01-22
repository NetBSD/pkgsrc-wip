# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kio-extras-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	http://kde.org/applications/internet/
COMMENT=	Additional components to increase the functionality of KIO
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config perl:run

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

REPLACE_PERL+=	info/kde-info2html

SUBST_CLASSES+=		paths fix-moc
SUBST_FILES.paths=	info/kde-info2html.conf
SUBST_VARS.paths=	LOCALBASE
SUBST_STAGE.paths=	post-patch

SUBST_STAGE.fix-moc=	post-configure
SUBST_MESSAGE.fix-moc=	Cleaning up MOC includes
SUBST_FILES.fix-moc=	_KDE_build/man/CMakeFiles/kmanpart_autogen.dir/AutogenInfo.cmake
SUBST_SED.fix-moc=	-e 's,;${PREFIX}/include;,;,g'

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
