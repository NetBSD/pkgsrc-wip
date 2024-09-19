# $NetBSD: options.mk,v 1.1 2015/04/07 04:53:22 makoto Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.mule
PKG_SUPPORTED_OPTIONS=	exclusive
# set exclusive option only when you don't have another version of emacsen
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	exclusive

#if exclusive is in PKG_OPTIONS, don't remove exclusive
.if empty(PKG_OPTIONS:Mexclusives)

post-install:
	(cd ${DESTDIR}${PREFIX}; \
	${RM}   bin/emacsclient bin/ctags bin/etags;	\
	)
.else
PLIST.exclusive=	YES
.endif
