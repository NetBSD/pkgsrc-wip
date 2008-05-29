# $NetBSD: options.mk,v 1.2 2008/05/29 11:34:09 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openaxiom
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		clisp sbcl

PKG_SUGGESTED_OPTIONS+=		clisp

PKG_SUPPORTED_OPTIONS+=		x11
PKG_SUGGESTED_OTIONS+=		x11

.include "../../mk/bsd.options.mk"

# Select Lisp backend
.if !empty(PKG_OPTIONS:Mclisp)
FASL=			fas
BUILD_DEPENDS+=		clisp>=2.41:../../lang/clisp
CONFIGURE_ARGS+=	--with-lisp=clisp
.endif
.if !empty(PKG_OPTIONS:Msbcl)
FASL=			fasl
BUILD_DEPENDS+=		sbcl-[0-9]*:../../lang/sbcl
CONFIGURE_ARGS+=	--with-lisp=sbcl
.endif

# Modify PLIST
PLIST_SUBST+=	FASL=${FASL}

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x=yes
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-x=no
.endif

.for opt in clisp sbcl
.if !empty(PKG_OPTIONS:M${opt})
PLIST_SUBST+=	${opt}=""
.else
PLIST_SUBST+=	${opt}="@comment "
.endif
.endfor
