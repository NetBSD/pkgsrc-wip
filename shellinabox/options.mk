# $NetBSD$

# cores: patches shellinaboxd to enable core dumps
# nologin: disable it and do login through ssh
PKG_OPTIONS_VAR=	PKG_OPTIONS.shellinabox
PKG_SUPPORTED_OPTIONS=	cores nologin
PKG_SUGGESTED_OPTIONS=	cores nologin

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnologin)
CONFIGURE_ARGS+=	--disable-login
.endif

.if !empty(PKG_OPTIONS:Mcores)
SUBST_CLASSES+=		cores
SUBST_STAGE.cores=	pre-patch
SUBST_MESSAGE.cores=	Enabling core files in shellinabox/shellinaboxd.c
SUBST_FILES.cores=	shellinabox/shellinaboxd.c
SUBST_SED.cores+=	-e 's|prctl(PR_SET_DUMPABLE,|// &|'
SUBST_SED.cores+=	-e 's|setrlimit(RLIMIT_CORE,|// &|'
.endif
