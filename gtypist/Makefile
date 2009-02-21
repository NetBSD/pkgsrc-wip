# $NetBSD: Makefile,v 1.9 2009/02/21 22:59:25 leot1990 Exp $
#

DISTNAME=		gtypist-2.8.3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=gtypist/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/gtypist/
COMMENT=		Universal typing tutor

#LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

# The *.typ files are not interpreted. They are normally accessed by
# starting gtypist with an argument.
CHECK_INTERPRETER_SKIP+=	share/gtypist/ru.typ
INFO_FILES=			yes
GNU_CONFIGURE=			yes
REPLACE_PERL+=			typefortune
USE_NCURSES=			yes	# uses typeahead()
USE_PKGLOCALEDIR=		yes
USE_TOOLS+=			makeinfo perl:run

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
