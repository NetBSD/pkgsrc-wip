# $NetBSD: Makefile,v 1.7 2014/02/11 21:04:10 noud4 Exp $
#

DISTNAME=		prpltwtr-0.12.0
CATEGORIES=		chat net
#MASTER_SITES=		http://prpltwtr.googlecode.com/files/

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://code.google.com/p/prpltwtr/
COMMENT=		Treat microblogging (Twitter, etc) as IM protocols
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=	prpltwtr
GIT_REPO.prpltwtr=	git://github.com/mikeage/prpltwtr.git

WRKSRC=			${WRKDIR}/prpltwtr
USE_TOOLS+=		autoconf
USE_TOOLS+=		automake
HAS_CONFIGURE=		yes
USE_TOOLS+=		perl
USE_LIBTOOL=		yes
CFLAGS+=		-I${BUILDLINK_DIR}/include/glib/glib-2.0 \
			-I${BUILDLINK_DIR}/lib/glib-2.0/include

INSTALLATION_DIRS+=	lib/pidgin lib/purple-2 \
			share/pixmaps/pidgin/protocols/16 \
			share/pixmaps/pidgin/protocols/22 \
			share/pixmaps/pidgin/protocols/48

pre-configure:
	${CP} ${FILESDIR}/Makefile.in.in  ${WRKSRC}/po
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
