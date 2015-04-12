# $NetBSD: Makefile,v 1.1 2015/04/12 16:33:06 krytarowski Exp $
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

USE_TOOLS+=	bison flex gm4 gmake bash

REPLACE_BASH+=	tests/aapits/bin/aapitsrun
REPLACE_BASH+=	tests/aapits/bin/cadir
REPLACE_BASH+=	tests/aapits/bin/run1
REPLACE_BASH+=	tests/aslts.sh
REPLACE_BASH+=	tests/aslts/bin/Do
REPLACE_BASH+=	tests/aslts/bin/asltsdiffres
REPLACE_BASH+=	tests/aslts/bin/asltsrun
REPLACE_BASH+=	tests/aslts/bin/bugstate/bdemosconc
REPLACE_BASH+=	tests/aslts/bin/bugstate/bdemossum
REPLACE_BASH+=	tests/aslts/bin/bugstate/bdemostabs
REPLACE_BASH+=	tests/aslts/bin/bugstate/parsebuglist
REPLACE_BASH+=	tests/aslts/bin/common
REPLACE_BASH+=	tests/aslts/bin/diffproc
REPLACE_BASH+=	tests/aslts/bin/settings
REPLACE_BASH+=	tests/templates/templates.sh

LICENSE=	gnu-gpl-v2 # OR intel-acpica-license
# According to https://acpica.org/faq
#   "Under what licensing is the ACPICA source released?
#      ACPICA can be licensed under the GNU General Public License or via a
#      separate license that may be more favorable to commercial OSVs. Please
#      see the source code license header for specifics.

do-test:
	cd tests ; ./aslts.sh || exit 1

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
