namespace Managed.Csharp {
    public interface IExternalApplication {
        /// <summary>
        /// Returns the <see cref="Entity"/> instance.
        /// </summary>
        /// <returns></returns>
        Entity GetEntity(int id);
    }
}