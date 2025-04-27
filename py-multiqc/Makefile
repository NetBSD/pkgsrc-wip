# $NetBSD$

DISTNAME=	multiqc-1.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multiqc/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/multiqc
COMMENT=	Aggregate bioinformatics analysis reports across samples and tools
LICENSE=	gnu-gpl-v3

# Use either py-kaleido (not in ports yet) or py-orca + py-psutil
# kaleido dep choreographer only works with chrome as of 2024-11-24
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-kaleido-[0-9]*:../../wip/py-kaleido
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-plotly>=5.1.8:../../graphics/py-plotly
DEPENDS+=	${PYPKGPREFIX}-yaml>=4:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-rich>=10:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-rich-click-[0-9]*:../../devel/py-rich-click
DEPENDS+=	${PYPKGPREFIX}-coloredlogs-[0-9]*:../../devel/py-coloredlogs
DEPENDS+=	${PYPKGPREFIX}-spectra>=0.0.10:../../graphics/py-spectra
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.7.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-typeguard-[0-9]*:../../devel/py-typeguard
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-dotenv-[0-9]*:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-natsort-[0-9]*:../../textproc/py-natsort
# FIXME: DEPENDS+=	${PYPKGPREFIX}-tiktoken>=0.7.0:../../textproc/py-tiktoken
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema

post-patch:
	${RM} ${WRKSRC}/multiqc/multiqc.py.orig

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
