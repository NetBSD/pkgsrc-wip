# $NetBSD: Makefile,v 1.1 2014/07/03 14:46:21 darcycain Exp $

DISTNAME=	openerp-7.0-${NIGHTLY}
PKGNAME=	openerp-server-7.0
CATEGORIES=	finance python
MASTER_SITES=	http://nightly.openerp.com/7.0/nightly/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openerp.com/
COMMENT=	Open source application ERP & CRM in Python using Postgresql
LICENSE=	gnu-agpl-v3

DEPENDS +=	${PYPKGPREFIX}-psycopg2>0:../../databases/py-psycopg2
DEPENDS +=	${PYPKGPREFIX}-babel>0:../../devel/py-babel
DEPENDS +=	${PYPKGPREFIX}-simplejson>0:../../converters/py-simplejson
DEPENDS +=	${PYPKGPREFIX}-chart>0:../../graphics/py-chart
DEPENDS +=	${PYPKGPREFIX}-dot>0:../../graphics/py-dot
DEPENDS +=	${PYPKGPREFIX}-libxslt>0:../../textproc/py-libxslt
DEPENDS +=	${PYPKGPREFIX}-lxml>0:../../textproc/py-lxml
DEPENDS +=	${PYPKGPREFIX}-yaml>0:../../textproc/py-yaml
DEPENDS +=	${PYPKGPREFIX}-mako>0:../../devel/py-mako
DEPENDS +=	${PYPKGPREFIX}-werkzeug>0:../../www/py-werkzeug
DEPENDS +=	${PYPKGPREFIX}-dateutil>0:../../time/py-dateutil
DEPENDS +=	${PYPKGPREFIX}-reportlab-[0-9]*:../../print/py-reportlab

NIGHTLY=	20140115-002435
WRKSRC=		${WRKDIR}/${DISTNAME}

RCD_SCRIPTS=	openerpd

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fixing path to python interpreter.
SUBST_SED.python+=	-e "s|/usr/bin/env python|${PYTHONBIN}|g"
SUBST_FILES.python+=	openerp/addons/base_quality_interrogation.py
SUBST_FILES.python+=	openerp/addons/document_ftp/ftpserver/ftpserver.py
SUBST_FILES.python+=	openerp/addons/email_template/html2text.py
SUBST_FILES.python+=	openerp/addons/l10n_fr_hr_payroll/report/fiche_paye.py
SUBST_FILES.python+=	openerp/addons/mail/static/scripts/openerp_mailgate.py
SUBST_FILES.python+=	openerp/report/render/rml2txt/rml2txt.py
SUBST_FILES.python+=	openerp/tests/test_mail.py
SUBST_FILES.python+=	openerp/tools/graph.py
SUBST_FILES.python+=	openerp/tools/test-config-values
SUBST_FILES.python+=	openerp/tools/which.py

post-build:
	${SED} -e "s#@PYSITELIB@#${PREFIX}/${PYSITELIB}#g" < \
		${FILESDIR}/openerp-server.conf.in > ${PREFIX}/etc/openerp-server.conf.sample

.include "../../lang/python/distutils.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
