# $NetBSD: Makefile,v 1.4 2013/10/14 12:47:17 makoto Exp $

# The name won't be used for actual fetch, this is cvs version
DISTNAME=	ja-FreeWnn-lib-1.11alpha22
PKGNAME=	ja-FreeWnn-lib-1.11alpha22

CATEGORIES=	inputmethod
MASTER_SITES=

LICENSE=	gnu-gpl-v2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://freewnn.sourceforge.jp/
COMMENT=	Japanese/Chinese/Korean input method (Japanese client library)
WRKSRC=		${WRKDIR}/FreeWnn

BUILD_TARGET=	all
INSTALL_TARGET=	install
BUILD_DEFS=	FREEWNN_USER FREEWNN_GROUP
INFO_FILES=	YES
USE_LIBTOOL=	YES

MAKE_JOBS_SAFE=	no

FREEWNN_USER=	wnn
FREEWNN_GROUP=	jserver
PKG_GROUPS=	${FREEWNN_GROUP}
PKG_USERS=	${FREEWNN_USER}:${FREEWNN_GROUP}

CVS_ROOT.FreeWnn=	:pserver:anonymous:@cvs.sourceforge.jp:/cvsroot/freewnn
CVS_REPOSITORIES=	FreeWnn

GNU_CONFIGURE=	YES

SPECIAL_PERMS+=	bin/Wnn4/jserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4711
SPECIAL_PERMS+=	bin/Wnn4/cserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4711
SPECIAL_PERMS+=	bin/Wnn4/tserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4711
SPECIAL_PERMS+=	bin/Wnn4/kserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4711


RCD_SCRIPTS=	ja_freewnn

#### 1 #####
SUBST_CLASSES+=		chown
SUBST_STAGE.chown=	pre-configure
# SPECIAL_PERMS will take care
SUBST_MESSAGE.chown=	Replacing 'chown' to harmless 'echo'

SUBST_FILES.chown+=	cdic/Makefile.in
SUBST_FILES.chown+=	Contrib/dic/gerodic/Makefile.in
SUBST_FILES.chown+=	cWnn/cdic/Makefile.in
SUBST_FILES.chown+=	cWnn/tdic/Makefile.in
SUBST_FILES.chown+=	kWnn/kdic/Makefile.in
SUBST_FILES.chown+=	Wnn/pubdicplus/Makefile.in
SUBST_FILES.chown+=	Wnn/wnncons/dic/Makefile.in

SUBST_SED.chown=	-e 's|chown |echo |'

#### 2 #####
SUBST_CLASSES+=		wnntouch
SUBST_STAGE.wnntouch=	pre-configure
# INSTALL script will take care
SUBST_MESSAGE.wnntouch=	Replacing 'wnntouch' to harmless 'echo'

SUBST_FILES.wnntouch+=	Contrib/dic/gerodic/Makefile.in
SUBST_FILES.wnntouch+=	cWnn/cdic/Makefile.in
SUBST_FILES.wnntouch+=	cWnn/tdic/Makefile.in
SUBST_FILES.wnntouch+=	kWnn/kdic/Makefile.in
SUBST_FILES.wnntouch+=	Wnn/pubdicplus/Makefile.in
SUBST_FILES.wnntouch+=	Wnn/wnncons/dic/Makefile.in

SUBST_SED.wnntouch=	-e 's|\$$(WNNTOUCH)|echo|'
SUBST_SED.wnntouch+=	-e 's|\$${WNNTOUCH}|echo|'

#### 3 #####
SUBST_CLASSES+=		wnnowner
SUBST_STAGE.wnnowner=	pre-configure
# INSTALL script will take care instead

SUBST_MESSAGE.wnnowner=	Replacing '-o ${WNNOWER}' to empty string
#   'INSTALL_FLAGS = -o ${WNNOWNER}' ->  'INSTFLAGS = '
# 'LOCAL_INSTFLAGS = -o $(WNNOWNER)' ->  'LOCAL_INSTFLAGS = '

SUBST_FILES.wnnowner+=	Wnn/jserver/Makefile.in
SUBST_FILES.wnnowner+=	Wnn/jutil/Makefile.in
SUBST_FILES.wnnowner+=	Wnn/pubdicplus/Makefile.in
SUBST_FILES.wnnowner+=	Wnn/wnncons/dic/Makefile.in
SUBST_FILES.wnnowner+=	Xwnmo/xjutil/Makefile.in
SUBST_FILES.wnnowner+=	Xwnmo/xwnmo/Makefile.in
SUBST_FILES.wnnowner+=	cWnn/cdic/Makefile.in
SUBST_FILES.wnnowner+=	cWnn/jserver/Makefile.in
SUBST_FILES.wnnowner+=	cWnn/jutil/Makefile.in
SUBST_FILES.wnnowner+=	cWnn/tdic/Makefile.in
SUBST_FILES.wnnowner+=	kWnn/jserver/Makefile.in
SUBST_FILES.wnnowner+=	kWnn/jutil/Makefile.in
SUBST_FILES.wnnowner+=	kWnn/kdic/Makefile.in

SUBST_FILES.wnnowner+=	Contrib/dic/gerodic/Makefile.in

SUBST_SED.wnnowner=	-e 's|-o \$${WNNOWNER}||'
#			Contrib/dic/gerodic/Makefile.in
SUBST_SED.wnnowner+=	-e 's|-o \$$(WNNOWNER)||'

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
