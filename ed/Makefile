# $NetBSD: Makefile,v 1.5 2003/12/03 09:39:52 jeremy-c-reed Exp $

DISTNAME=		ed-0.2
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor

GNU_CONFIGURE=		YES
INFO_FILES=		ed.info

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
# the ./configure accepts --program-prefix, but doesn't use
MAKE_ENV+=		binprefix="${GNU_PROGRAM_PREFIX}"
.endif
PLIST_SUBST+=           GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=            GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
