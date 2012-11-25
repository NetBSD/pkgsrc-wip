# $NetBSD: Makefile,v 1.12 2012/11/25 23:32:20 othyro Exp $
#

DISTNAME=		gtypist-2.8.3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=gtypist/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gtypist/
COMMENT=		Universal typing tutor
LICENSE=		gnu-gpl-v3

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
