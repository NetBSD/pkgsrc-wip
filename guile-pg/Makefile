# $NetBSD: Makefile,v 1.1.1.1 2004/11/12 20:19:01 lexort Exp $
#

DISTNAME=	guile-pg-0.22
CATEGORIES=	databases
MASTER_SITES=	http://www.glug.org/people/ttn/software/guile-pg/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.glug.org/people/ttn/software/guile-pg/
COMMENT=	PostgreSQL interface for Guile

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

INFO_FILES=	guile-pg.info

# guile-pg uses the deprecated feature of binary modules, and places
# both the binary module and the scheme code for modules in
# $GUILE_LIBSITE, which is searched by ttn's (guile-pg maintainer)
# version of guile, but not by guile 1.6.x.  The simplest
# nonproblematic solution is to symlink the installed code to where
# guile expects it.  We could patch guile-pg to install in
# /usr/pkg/share/guile/site, but it installs a shared library which
# of course cannot go in share.
post-install:
	cd ${PREFIX}/share/guile/site && ${LN} -sf ../../../lib/guile/site/database .

PGSQL_VERSION_REQD=	74

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
