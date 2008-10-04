# $NetBSD: Makefile,v 1.6 2008/10/04 16:40:23 leot1990 Exp $
#

DISTNAME=		gtypist-2.8.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=gtypist/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/gtypist/
COMMENT=		Universal typing tutor

PKG_DESTDIR_SUPPORT=	user-destdir

# The *.typ files aren not interpreted. They are normally accessed by
# starting gtypist with an argument.
CHECK_INTERPRETER_SKIP+=	share/gtypist/ru.typ
INFO_FILES=			yes
GNU_CONFIGURE=			yes
REPLACE_PERL+=			typefortune
USE_NCURSES=			yes	# uses typeahead()
USE_PKGLOCALEDIR=		yes
USE_TOOLS+=			makeinfo perl:run

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
