# $NetBSD: options.mk,v 1.1 2013/03/25 15:52:51 hfath Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.tsm
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	java

.if !empty(PKG_OPTIONS:Mjava)

USE_TOOLS+=		bash:run

SUBST_CLASSES+=		bash_path
SUBST_STAGE.bash_path=	post-install
SUBST_FILES.bash_path=	.destdir/usr/pkg/emul/linux/opt/tivoli/tsm/client/ba/bin/dsmj
SUBST_SED.bash_path=	-e "s|/.*/bash|${TOOLS_PATH.bash}|g"

USE_JAVA=		run
USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk7

PLIST.java=		yes
PUBLIC_BINS+=		dsmj

.include "../../mk/java-vm.mk"
.endif
