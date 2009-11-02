# $NetBSD: Makefile,v 1.2 2009/11/02 16:57:26 schnoebe Exp $

DISTNAME=		gloox-1.0
CATEGORIES=		chat
MASTER_SITES=		http://camaya.net/download/
EXTRACT_SUFX=		.tar.bz2

# Second paragraph - MAINTAINER/OWNER, HOMEPAGE and COMMENT, and LICEN[CS]E
MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://camaya.net/gloox
COMMENT=		Jabber/XMPP client library
LICENSE=		gnu-gpl-v2

# if the package can be created without root privileges
PKG_DESTDIR_SUPPORT=	user-destdir

# SVN configuration
# SVN_REPOSITORIES=	gloox
# SVN_ROOT.gloox=		svn://svn.camaya.net/gloox/branches/1.0
# SVN_MODULE.gloox=	gloox-1.0

# .include "../../wip/mk/svn-package.mk"

GNU_CONFIGURE=		yes

# Sixth paragraph - file overrides; these are all *_OVERRIDE variables
USE_LANGUAGES+=		c++ c
USE_TOOLS+=		autoconf automake
USE_LIBTOOL=		yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

.include "options.mk"

# post-patch:
# 	cd ${WRKSRC} && sh ./autogen.sh

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
