using System.Windows.Forms;

namespace Managed.Csharp {
    public class Program {

        private static IExternalApplication _externalApplication;

        /// <summary>
        /// Sets the <see cref="IExternalApplication"/> interface.
        /// </summary>
        /// <param name="externalApplication"></param>
        /// <returns></returns>
        public static void SetExternalApplication(IExternalApplication externalApplication) {
            _externalApplication = externalApplication;

            // test
            var entity = _externalApplication.GetEntity(1234);
            MessageBox.Show(string.Format("Id={0}; Name={1}", entity.id, entity.name));
        }
    }
}