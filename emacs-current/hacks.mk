# $NetBSD: hacks.mk,v 1.2 2016/04/12 13:25:21 ryoon Exp $

.if !defined(EMACS_HACKS_MK)
EMACS_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### PaX is enabled, bootstrap-emacs command dumps core with segfault.
### src/Makefile.in does not support NetBSD paxctl(8) syntax.
###
.  if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
.    if exists(/usr/sbin/paxctl)
SUBST_CLASSES+=			paxctl
SUBST_STAGE.paxctl=		pre-configure
SUBST_MESSAGE.paxctl=		Setting paxctl command
SUBST_FILES.paxctl+=		src/Makefile.in
SUBST_SED.paxctl+=		-e 's,$$(PAXCTL_if_present) -zex,/usr/sbin/paxctl +a,g'
SUBST_SED.paxctl+=		-e 's,$$(PAXCTL_if_present) -r,/usr/sbin/paxctl +a,g'
.    endif
.  endif

.endif  # EMACS_HACKS_MK
