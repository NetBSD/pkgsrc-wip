# $NetBSD: Makefile,v 1.1.1.1 2012/01/11 23:36:33 noud4 Exp $
#

DISTNAME=		purple-translate-1.1
CATEGORIES=		chat
MASTER_SITES=		http://purple-translate.googlecode.com/files/

MAINTAINER=		noud@home.nl
HOMEPAGE=		http://code.google.com/p/purple-translate/
COMMENT=		Automatically translates messages in Pidgin
LICENSE=		gnu-gpl-v3

SVN_REPOSITORIES=	translate
SVN_ROOT.translate=	http://purple-translate.googlecode.com/svn/trunk/
SVN_MODULE.translate=	purple-translate

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/purple-translate
BUILD_TARGET=		purple-translate.so

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix+=	-e 's,@BUILDLINK_DIR@,${BUILDLINK_DIR},g'
SUBST_SED.prefix+=	-e 's,@DESTDIR@,${DESTDIR},g'
SUBST_SED.prefix+=	-e 's,@PREFIX@,${PREFIX},'

INSTALLATION_DIRS+=	lib/purple-2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
