# $NetBSD: options.mk,v 1.2 2015/11/25 12:51:54 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libreoffice
PKG_SUPPORTED_OPTIONS=	java debug kde4 gtk3

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS=	java
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	java kde4 gtk3

.if !empty(PKG_OPTIONS:Mjava)
.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
USE_JAVA=		yes
USE_JAVA2=		yes
TOOL_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant
CONFIGURE_ARGS+=	--with-ant-home=${PREFIX}

DEPENDS+=		hsqldb18-[0-9]*:../../databases/hsqldb18
CONFIGURE_ARGS+=	--with-hsqldb-jar=${PREFIX}/lib/java/hsqldb18/hsqldb.jar
CONFIGURE_ARGS+=	--enable-ext-wiki-publisher \
			--with-java \
			--with-jdk-home=${PKG_JAVA_HOME} \
			--without-system-beanshell \
			--enable-scripting-beanshell \
			--with-system-hsqldb \
			--without-system-jfreereport
PLIST_SRC+=		${PLIST_SRC_DFLT:Q} ${PKGDIR}/PLIST.java
.  if ${PKG_JVM} == openjdk7
CONFIGURE_ARGS+=	--disable-scripting-javascript
.  else
PLIST_SRC+=		${PKGDIR}/PLIST.javascript
.  endif
PLIST.java=		yes
.else
CONFIGURE_ARGS+=	--without-java
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--enable-selective-debuginfo="all"
PLIST_SRC=		${PLIST_SRC_DFLT:Q} ${PKGDIR}/PLIST.debug
.else
CONFIGURE_ARGS+=	--enable-release-build
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gtk3
PLIST.gtk3=		yes
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk3
.endif

.if !empty(PKG_OPTIONS:Mkde4)
CONFIGURE_ARGS+=	--enable-kde4
CONFIGURE_ENV+=		KDE4DIR="${PREFIX}"
PLIST.kde4=		yes
.include "../../x11/kdelibs4/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-kde4
.endif
