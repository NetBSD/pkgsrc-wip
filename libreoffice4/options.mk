# $NetBSD: options.mk,v 1.1 2013/09/24 12:51:50 ryo-on Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libreoffice4
PKG_SUPPORTED_OPTIONS=	java
PKG_SUGGESTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	java

.if !empty(PKG_OPTIONS:Mdoc)
USE_JAVA=		yes
BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant
FIND_PREFIX:=		ANTDIR=apache-ant
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--enable-ext-wiki-publisher \
			--with-java \
			--with-jdk-home=${PKG_JAVA_HOME} \
			--with-ant-home=${ANTDIR}/ant
.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--without-java
.endif
