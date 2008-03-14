# $NetBSD: options.mk,v 1.1 2008/03/14 12:29:17 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openaxiom
PKG_OPTIONS_REQUIRED_GROUPS=	lisp
PKG_OPTIONS_GROUP.lisp=		clisp sbcl gcl

# The only officially supported for now, GCL:
PKG_SUGGESTED_OPTIONS+=		gcl

PKG_SUPPORTED_OPTIONS+=		x11
PKG_SUGGESTED_OTIONS+=		x11

.include "../../mk/bsd.options.mk"

# Select Lisp backend
.if !empty(PKG_OPTIONS:Mclisp)
#BIN=			fas
BUILD_DEPENDS+=		clisp>=2.41:../../lang/clisp
CONFIGURE_ARGS+=	--with-lisp=clisp
.endif
.if !empty(PKG_OPTIONS:Msbcl)
#BIN=			fasl
BUILD_DEPENDS+=		sbcl-[0-9]*:../../lang/sbcl
CONFIGURE_ARGS+=	--with-lisp=sbcl
.endif
.if !empty(PKG_OPTIONS:Msbcl)
#BIN=			fasl
BUILD_DEPENDS+=		gcl>=2.6.7:../../lang/gcl
CONFIGURE_ARGS+=	--with-lisp=gcl
#CONFIGURE_ARGS+=	AXIOM_LISP=/usr/pkg/bin/clisp
#CONFIGURE_ENV+=		AXIOM_LISP=/usr/pkg/bin/clisp
.endif

# Modify PLIST
PLIST_SUBST+=	BIN=${BIN:Q}

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x=yes
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-x=no
.endif

.for opt in clisp sbcl gcl
.if !empty(PKG_OPTIONS:M${opt})
PLIST_SUBST+=	${opt}=""
.else
PLIST_SUBST+=	${opt}="@comment "
.endif
.endfor
