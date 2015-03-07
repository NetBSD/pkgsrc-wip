# $NetBSD: Makefile,v 1.4 2015/03/07 13:19:37 krytarowski Exp $
#

GIT_REPOSITORIES=	acpica-utils
GIT_REPO.acpica-utils=	git@github.com:acpica/acpica.git

DISTNAME=	acpica
PKGNAME=	acpica-utils-git
CATEGORIES=	devel
MASTER_SITES=	http://www.acpica.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acpica.org/
COMMENT=	Intel ACPI CA Unix utilities

USE_TOOLS+=	bison flex gm4 gmake

LICENSE=	gnu-gpl-v2 # OR intel-acpica-license
# According to https://acpica.org/faq
#   "Under what licensing is the ACPICA source released?
#      ACPICA can be licensed under the GNU General Public License or via a
#      separate license that may be more favorable to commercial OSVs. Please
#      see the source code license header for specifics.

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
